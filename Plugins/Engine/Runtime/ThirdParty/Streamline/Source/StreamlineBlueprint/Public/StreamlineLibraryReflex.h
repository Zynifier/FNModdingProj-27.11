// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StreamlineLibraryReflex.generated.h"

enum class UStreamlineFeatureSupport : uint8;
enum class UStreamlineReflexMode : uint8;

UENUM(BlueprintType)
enum class UStreamlineReflexMode : uint8
{
	Disabled = 0 UMETA(DisplayName="Disabled"),
	Enabled = 1 UMETA(DisplayName="Enabled"),
	EnabledPlusBoost = 3 UMETA(DisplayName="Enabled + Boost"),
};

UCLASS(MinimalAPI)
class UStreamlineLibraryReflex : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Streamline|Reflex", meta=(DisplayName="Get default Reflex mode"))
	static UStreamlineReflexMode GetDefaultReflexMode();

	UFUNCTION(BlueprintPure, Category="Streamline|Reflex", meta=(DisplayName="Get Reflex Game Latency (ms)"))
	static float GetGameLatencyInMs();

	UFUNCTION(BlueprintPure, Category="Streamline|Reflex", meta=(DisplayName="Get Reflex Game To Render Latency (ms)"))
	static float GetGameToRenderLatencyInMs();

	UFUNCTION(BlueprintPure, Category="Streamline|Reflex", meta=(DisplayName="Get Reflex mode"))
	static UStreamlineReflexMode GetReflexMode();

	UFUNCTION(BlueprintPure, Category="Streamline|Reflex", meta=(DisplayName="Get Reflex Render Latency (ms)"))
	static float GetRenderLatencyInMs();

	UFUNCTION(BlueprintPure, Category="Streamline|Reflex", meta=(DisplayName="Is NVIDIA Reflex Supported"))
	static bool IsReflexSupported();

	UFUNCTION(BlueprintPure, Category="Streamline|Reflex", meta=(DisplayName="Query NVIDIA Reflex Support"))
	static UStreamlineFeatureSupport QueryReflexSupport();

	UFUNCTION(BlueprintCallable, Category="Streamline|Reflex", meta=(DisplayName="Set Reflex mode"))
	static void SetReflexMode(const UStreamlineReflexMode Mode);

};

