// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "DLSSLibrary.generated.h"

class UObject;
enum class UDLSSMode : uint8;
enum class UDLSSSupport : uint8;

UENUM(BlueprintType)
enum class UDLSSMode : uint8
{
	Off = 0 UMETA(DisplayName="Off"),
	/** Not a real quality mode. Use Auto to query best settings for a given resolution with GetDLSSModeInformation */
	Auto = 1 UMETA(DisplayName="Auto"),
	UltraQuality = 2 UMETA(DisplayName="Ultra Quality"),
	Quality = 3 UMETA(DisplayName="Quality"),
	Balanced = 4 UMETA(DisplayName="Balanced"),
	Performance = 5 UMETA(DisplayName="Performance"),
	UltraPerformance = 6 UMETA(DisplayName="Ultra Performance"),
};

UENUM(BlueprintType)
enum class UDLSSSupport : uint8
{
	Supported = 0 UMETA(DisplayName="Supported"),
	NotSupported = 1 UMETA(DisplayName="Not Supported"),
	/** DLSS requires an NVIDIA RTX GPU */
	NotSupportedIncompatibleHardware = 2 UMETA(DisplayName="Incompatible Hardware"),
	/** The driver is outdated. Also see GetDLSSMinimumDriverVersion */
	NotSupportedDriverOutOfDate = 3 UMETA(DisplayName="Driver Out of Date"),
	/** DLSS requires at least Windows 10 Fall 2017 Creators Update 64-bit, (v1709, build 16299) */
	NotSupportedOperatingSystemOutOfDate = 4 UMETA(DisplayName="Operating System Out of Date"),
	/** This platform doesn't not support DLSS at build time. Currently DLSS is only supported on Windows 64 */
	NotSupportedByPlatformAtBuildTime = 5 UMETA(DisplayName="Platform Not Supported At Build Time"),
	/** DLSS is not compatible with an active API capture tool such as RenderDoc. */
	NotSupportedIncompatibleAPICaptureToolActive = 6 UMETA(DisplayName="Incompatible API Capture Tool Active"),
};

UCLASS(MinimalAPI)
class UDLSSLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Enable/disable DLAA. Note that while DLAA is enabled, DLSS will be automatically disabled */
	UFUNCTION(BlueprintCallable, Category="DLSS", meta=(DeprecatedFunction, DeprecationMessage="Use EnableDLSS instead", DisplayName="Enable DLAA"))
	static void EnableDLAA(bool bEnabled);

	/**
	 * Enable/disable DLSS/DLAA
	 * To select a DLSS quality mode, set an appropriate upscale screen percentage with r.ScreenPercentage. Use GetDlssModeInformation to find optimal screen percentage
	 * To select DLAA, set the upscale screen percentage to 100 (r.ScreenPercentage=100)
	 */
	UFUNCTION(BlueprintCallable, Category="DLSS", meta=(DisplayName="Enable DLSS"))
	static void EnableDLSS(bool bEnabled);

	/* Find a reasonable default DLSS mode based on current hardware */
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Get Default DLSS Mode"))
	static UDLSSMode GetDefaultDLSSMode();

	/** If QueryDLSSSupport returns "NotSupportedDriverOutOfDate", then MinDriverVersionMajor and MinDriverVersionMinor contains the required driver version.*/
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Get DLSS Minimum DriverVersion"))
	static void GetDLSSMinimumDriverVersion(int32& MinDriverVersionMajor, int32& MinDriverVersionMinor);

	/* Reads the console variables to infer the current DLSS mode (r.NGX.DLSS.Enable, r.NGX.DLSS.Quality, r.TemporalAA.Upscaler)*/
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DeprecatedFunction, DeprecationMessage="Use IsDLSSEnabled instead", DisplayName="Get DLSS Mode"))
	static UDLSSMode GetDLSSMode();

	/** Provides additional details (such as screen percentage ranges) about a DLSS mode. Screen Resolution is required for Auto mode */
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Get DLSS Mode Information"))
	static void GetDLSSModeInformation(UDLSSMode DLSSMode, FVector2D ScreenResolution, bool& bIsSupported, float& OptimalScreenPercentage, bool& bIsFixedScreenPercentage, float& MinScreenPercentage, float& MaxScreenPercentage, float& OptimalSharpness);

	/** The global screen percentage range that DLSS supports. Excludes DLSS modes with fixed screen percentage. Also see GetDLSSModeInformation*/
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Get DLSS Screenpercentage Range"))
	static void GetDLSSScreenPercentageRange(float& MinScreenPercentage, float& MaxScreenPercentage);

	/*Reads the console variables to infer the current DLSS sharpness (r.NGX.DLSS.Sharpness) */
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Get DLSS Sharpness"))
	static float GetDLSSSharpness();

	/** Retrieves all supported DLSS modes. Can be used to populate UI */
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Get Supported DLSS Modes"))
	static TArray<UDLSSMode> GetSupportedDLSSModes();

	/** Checks whether DLAA is enabled */
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DeprecatedFunction, DeprecationMessage="Use IsDLSSEnabled instead", DisplayName="Is DLAA Enabled"))
	static bool IsDLAAEnabled();

	/** Checks whether DLSS/DLAA is enabled */
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Is DLSS Enabled"))
	static bool IsDLSSEnabled();

	/** Checks whether a DLSS mode is supported */
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Is DLSS Mode Supported"))
	static bool IsDLSSModeSupported(UDLSSMode DLSSMode);

	/** Checks whether DLSS/DLAA is supported by the current GPU. Further details can be retrieved via QueryDLSSSupport*/
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Is NVIDIA DLSS Supported"))
	static bool IsDLSSSupported();

	/** Checks whether DLSS/DLAA is supported by the current GPU	*/
	UFUNCTION(BlueprintPure, Category="DLSS", meta=(DisplayName="Query NVIDIA DLSS Support"))
	static UDLSSSupport QueryDLSSSupport();

	/** Sets the console variables to enable/disable DLSS (r.NGX.DLSS.Enable, r.NGX.DLSS.Quality)*/
	UFUNCTION(BlueprintCallable, Category="DLSS", meta=(DeprecatedFunction, DeprecationMessage="Use EnableDLSS instead", DisplayName="Set DLSS Mode", WorldContext="WorldContextObject"))
	static void SetDLSSMode(UObject* WorldContextObject, UDLSSMode DLSSMode);

	/* Sets the console variables to enable additional DLSS sharpening. Set to 0 to disable (r.NGX.DLSS.Sharpness) */
	UFUNCTION(BlueprintCallable, Category="DLSS", meta=(DisplayName="Set DLSS Sharpness"))
	static void SetDLSSSharpness(float Sharpness);

};

