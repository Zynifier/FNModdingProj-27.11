// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HarmonixDsp/FusionSampler/Settings/FusionPatchSettings.h"
#include "HarmonixDsp/FusionSampler/Settings/KeyzoneSettings.h"
#include "FusionPatch.generated.h"

class UAssetImportData;
class UFusionPatch;
enum class EFusionPatchAudioLoadResult : uint8;

UENUM(BlueprintType)
enum class EFusionPatchAudioLoadResult : uint8
{
	Success = 0,
	Fail = 1,
	Cancelled = 2,
};

/**
* Called when a load request for a sound has completed.
*/
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnFusionPatchLoadComplete, const UFusionPatch*, LoadedFusionPatch, EFusionPatchAudioLoadResult, LoadResult);

// User facing data of FusionPatch

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FFusionPatchData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Presets")
	TArray<FKeyzoneSettings> Keyzones;

	UPROPERTY(EditAnywhere, Category="Presets")
	TArray<FFusionPatchSettings> Presets;

	UPROPERTY(EditAnywhere, Category="Presets")
	int32 CurrentPresetIndex;

};

UCLASS(BlueprintType, meta=(DisplayName="Fusion Patch"))
class HARMONIXDSP_API UFusionPatch : public UObject
{
	GENERATED_BODY()

public:
	/*
	* Cancels the active load request if one has been made and has not finished yet.
	* Will trigger callbacks with "Cancelled" load result.
	* Will do nothing if there is no active load request.
	* 
	* Note: Cancelling the load request unfortunately does not stop any pending async tasks.
	* So the load will complete, we'll just discard the loaded data,
	* and "Release" any audio that has been loaded
	*/
	UFUNCTION(BlueprintCallable, Category="Fusion Patch")
	void CancelAudioLoadRequest();

	/*
	* Will only return `true` if "Load Audio For Playback" has been called and completed.
	* 
	* @return	Whether the streaming audio is fully loaded and Retained
	*/
	UFUNCTION(BlueprintPure, Category="Fusion Patch")
	bool IsAudioLoadedForPlayback() const;

	/*
	* Request Async load of compressed audio data for playback
	* 
	* Unless you do this, audio for fusion patches will be streamed by default.
	* 
	* Once loaded, the audio data will be "Retained" in the Streaming Cache.
	* Call "ReleaseLoadedAudio()" to allow the loaded audio to be unloaded to make space in the Streaming Cache.
	* If you don't Release the loaded audio, the audio can stay in the cache longer than the lifetime of the FusionPatch 
	* as long as there are still live references to the underlying StreamingAudioData
	* 
	* @param OnLoadComplete		Callback called once when audio load completes with load result (Succes, Fail, Cancelled)
	*/
	UFUNCTION(BlueprintCallable, Category="Fusion Patch")
	void LoadAudioForPlayback(const FOnFusionPatchLoadComplete OnLoadComplete);

	/*
	* "Release" references to loaded audio and "cancels" any pending load requests.
	* (internally calls CancelAudioLoadRequest)
	* 
	* "Releasing" loaded audio does not "unload" it from the cache, 
	* but rather lets the cache know that the loaded audio can be discarded.
	* This has the added benifit that calling "LoadAudioForPlayback" again
	* could result in a cache "Hit" on future loads, until the audio data is fully unloaded.
	*/
	UFUNCTION(BlueprintCallable, Category="Fusion Patch")
	void ReleaseLoadedAudio();

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Instanced, Category="ImportSettings")
	TObjectPtr<UAssetImportData> AssetImportData;
#endif

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fusion Patch")
	FFusionPatchData FusionPatchData;

};

