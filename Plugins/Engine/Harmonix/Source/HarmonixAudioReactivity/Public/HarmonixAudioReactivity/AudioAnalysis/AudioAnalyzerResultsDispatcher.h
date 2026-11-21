// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "HarmonixAudioReactivity/AudioAnalysis/AudioAnalyzerResults.h"
#include "AudioAnalyzerResultsDispatcher.generated.h"

class UHarmonixAudioAnalyzerResultsProvider;

/**
 * @brief Allows analyzers to dispatch results from the audio render thread to other threads.
 */
UCLASS()
class HARMONIXAUDIOREACTIVITY_API UHarmonixAudioAnalyzerResultsDispatcher : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	/**
	 * @brief Check to see if a provider with the specified name has been registered.
	 * @param Name - The name of the provider
	 * @return true if a provider is registered with the specified name, false otherwise
	 */
	UFUNCTION(BlueprintPure, Category="AudioAnalysis")
	bool HasProvider(const FName& Name) const;

	/**
	 * @brief Try to get the latest results from a named provider.
	 * @param Name - The name of the provider
	 * @param Results - The results, if the provider exists
	 * @return true if the provider exists, false otherwise
	 */
	UFUNCTION(BlueprintPure, Category="AudioAnalysis")
	bool TryGetResults(const FName& Name, FHarmonixAudioAnalyzerResults& Results) const;

};

/**
 * @brief A mechanism by which Blueprints can provide audio analysis results to consumers of those results.
 */
UCLASS(BlueprintType)
class HARMONIXAUDIOREACTIVITY_API UHarmonixAudioAnalyzerResultsProvider : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	static UHarmonixAudioAnalyzerResultsProvider* CreateHarmonixAudioAnalyzerResultsProvider(FName Name = NAME_None);

	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	void SetArbitraryTextureData(const TArray<float>& ArbitraryTextureData);

};

