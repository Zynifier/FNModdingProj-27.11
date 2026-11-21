// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StreamlineLibraryDLSSG.generated.h"

enum class UStreamlineDLSSGMode : uint8;
enum class UStreamlineFeatureSupport : uint8;

UENUM(BlueprintType)
enum class UStreamlineDLSSGMode : uint8
{
	Off = 0 UMETA(DisplayName="Off"),
	On = 1 UMETA(DisplayName="On"),
};

UCLASS(MinimalAPI)
class UStreamlineLibraryDLSSG : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/* Find a reasonable default DLSS-G mode based on current hardware */
	UFUNCTION(BlueprintPure, Category="Streamline|DLSS-G", meta=(DisplayName="Get Default DLSS-G Mode"))
	static UStreamlineDLSSGMode GetDefaultDLSSGMode();

	/* Returns the actual framerate and number of frames presented, whether DLSS-G is active or not */
	UFUNCTION(BlueprintPure, Category="Streamline|DLSS-G", meta=(DisplayName="Get DLSS-G frame frame rate and presented frames"))
	static void GetDLSSGFrameTiming(float& FrameRateInHertz, int32& FramesPresented);

	/* Reads the console variables to infer the current DLSS-G mode*/
	UFUNCTION(BlueprintPure, Category="Streamline|DLSS-G", meta=(DisplayName="Get DLSS-G Mode"))
	static UStreamlineDLSSGMode GetDLSSGMode();

	/** Retrieves all supported DLSS-G modes. Can be used to populate UI */
	UFUNCTION(BlueprintPure, Category="Streamline|DLSS-G", meta=(DisplayName="Get Supported DLSS-G Modes"))
	static TArray<UStreamlineDLSSGMode> GetSupportedDLSSGModes();

	/** Checks whether a DLSS-G mode is supported */
	UFUNCTION(BlueprintPure, Category="Streamline|DLSS-G", meta=(DisplayName="Is DLSS-G Mode Supported"))
	static bool IsDLSSGModeSupported(UStreamlineDLSSGMode DLSSGMode);

	/** Checks whether DLSS-G is supported by the current GPU. Further details can be retrieved via QueryDLSSGSupport*/
	UFUNCTION(BlueprintPure, Category="Streamline|DLSS-G", meta=(DisplayName="Is NVIDIA DLSS-G Supported"))
	static bool IsDLSSGSupported();

	/** Checks whether DLSS-G is supported by the current GPU	*/
	UFUNCTION(BlueprintPure, Category="Streamline|DLSS-G", meta=(DisplayName="Query NVIDIA DLSS-G Support"))
	static UStreamlineFeatureSupport QueryDLSSGSupport();

	/** Sets the console variables to enable/disable DLSS-G*/
	UFUNCTION(BlueprintCallable, Category="Streamline|DLSS-G", meta=(DisplayName="Set DLSS-G Mode"))
	static void SetDLSSGMode(UStreamlineDLSSGMode DLSSGMode);

};

