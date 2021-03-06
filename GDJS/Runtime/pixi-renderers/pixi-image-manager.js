/*
 * GDevelop JS Platform
 * Copyright 2013-2016 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the MIT License.
 */

/**
 * PixiImageManager loads and stores textures that can be used by the objects.
 *
 * @class PixiImageManager
 * @namespace gdjs
 * @param runtimeGame The runtimeGame to be imageManager belongs to.
 */
gdjs.PixiImageManager = function(resources)
{
    this._resources = resources;
    this._invalidTexture = PIXI.Texture.fromImage("bunny.png"); //TODO
    this._loadedTextures = new Hashtable();
};

gdjs.ImageManager = gdjs.PixiImageManager; //Register the class to let the engine use it.

/**
 * Return the PIXI texture associated to the specified name.
 * Returns a placeholder texture if not found.
 * @param name The name of the texture to get.
 * @method getPIXITexture
 */
gdjs.PixiImageManager.prototype.getPIXITexture = function(name) {
	if ( this._loadedTextures.containsKey(name) ) {
		return this._loadedTextures.get(name);
	}
	if ( name === "" ) {
		return this._invalidTexture;
	}

	//Texture is not loaded, load it now from the resources list.
	if ( this._resources ) {
		var texture = null;
		gdjs.iterateOverArray(this._resources, function(res) {
			if ( res.name === name &&
				res.kind === "image" ) {

				texture = PIXI.Texture.fromImage(res.file);
				return false;
			}
		});

		if ( texture !== null ) {
			console.log("Loaded texture \""+name+"\".");
			this._loadedTextures.put(name, texture);
			return texture;
		}
	}

	console.warn("Unable to find texture \""+name+"\".");
	return this._invalidTexture;
};

/**
 * Return a PIXI texture which can be used as a placeholder when no
 * suitable texture can be found.
 * @method getInvalidPIXITexture
 */
gdjs.PixiImageManager.prototype.getInvalidPIXITexture = function() {
	return this._invalidTexture;
};


/**
 * Load the specified resources, so that textures are loaded and can then be
 * used by calling `getPIXITexture`.
 * @param onProgress Callback called each time a new file is loaded.
 * @param onComplete Callback called when loading is done.
 * @param resources The resources to be loaded. If not specified, will load the resources
 * specified in the PixiImageManager constructor.
 * @method loadTextures
 */
gdjs.PixiImageManager.prototype.loadTextures = function(onProgress, onComplete, resources) {
	resources = resources || this._resources;

	//Construct the list of files to be loaded.
	//For one loaded file, it can have one or more resources
	//that use it.
    var that = this;
    var files = {};
    gdjs.iterateOverArray(resources, function(res) {
        if ( res.file && res.kind === "image" ) {
        	if (that._loadedTextures.containsKey(res.name)) {
				console.log("Texture \"" + res.name + "\" is already loaded.");
        		return true;
        	}

            files[res.file] = files[res.file] ? files[res.file].concat(res) : [res];
        }
    });

    var totalCount = Object.keys(files).length;
    if (totalCount === 0)
    	return onComplete(); //Nothing to load.

    var loadingCount = 0;
    var loader = PIXI.loader;
    loader.once('complete', function(loader, loadedFiles) {
    	//Store the loaded textures so that they are ready to use.
    	for (var file in loadedFiles) {
    		if (loadedFiles.hasOwnProperty(file)) {
    			if (!files.hasOwnProperty(file)) continue;

    			files[file].forEach(function(res) {
    				that._loadedTextures.put(res.name, loadedFiles[file].texture);
                    if (!res.smoothed) {
                        loadedFiles[file].texture.baseTexture.scaleMode =
                            PIXI.SCALE_MODES.NEAREST;
                    }
    			});
    		}
    	}

    	onComplete();
    });
    loader.on('progress', function() {
    	loadingCount++;
    	onProgress(loadingCount, totalCount);
    });

	for (var file in files) {
		if (files.hasOwnProperty(file)) {
            loader.add(file, file);
        }
    }

    loader.load();
}
