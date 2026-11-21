// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StreamlineLibrary.generated.h"

enum class UStreamlineFeature : uint8;
enum class UStreamlineFeatureRequirementsFlags : uint8;
enum class UStreamlineFeatureSupport : uint8;

UENUM(BlueprintType)
enum class UStreamlineFeature : uint8
{
	DLSSG = 0 UMETA(DisplayName="DLSS Frame Generation"),
	Reflex = 1 UMETA(DisplayName="Reflex"),
	Count = 2 UMETA(Hidden),
};

UENUM(BlueprintType, meta=(Bitflags))
enum class UStreamlineFeatureRequirementsFlags : uint8
{
	None = 0,
	D3D11Supported = 1,
	D3D12Supported = 2,
	VulkanSupported = 4,
	VSyncOffRequired = 8,
	HardwareSchedulingRequired = 16,
};

UENUM(BlueprintType)
enum class UStreamlineFeatureSupport : uint8
{
	Supported = 0 UMETA(DisplayName="Supported"),
	NotSupported = 1 UMETA(DisplayName="Not Supported"),
	/** This feature requires an NVIDIA RTX GPU */
	NotSupportedIncompatibleHardware = 2 UMETA(DisplayName="Incompatible Hardware"),
	/** The driver is outdated. Also see GetStreamlineFeatureGMinimumDriverVersion */
	NotSupportedDriverOutOfDate = 3 UMETA(DisplayName="Driver Out of Date"),
	/** The Operating System is outdated. Also see GetStreamlineFeatureMinimumOperatingSystemVersion */
	NotSupportedOperatingSystemOutOfDate = 4 UMETA(DisplayName="Operating System Out of Date"),
	/** This feature requires Windows Hardware Scheduling to be Enabled */
	NotSupportedHardewareSchedulingDisabled = 5 UMETA(DisplayName="Hardware Scheduling Disabled"),
	/** This RHI doesn't not support this feature run time. */
	NotSupportedByRHI = 6 UMETA(DisplayName="Not supported by RHI"),
	/** This platform doesn't not support this feature at build time. Currently this feature is only supported on Windows 64 */
	NotSupportedByPlatformAtBuildTime = 7 UMETA(DisplayName="Platform Not Supported At Build Time"),
	/** This feature is not compatible with an active API capture tool such as RenderDoc. */
	NotSupportedIncompatibleAPICaptureToolActive = 8 UMETA(DisplayName="Incompatible API Capture Tool Active"),
};

USTRUCT(BlueprintType)
struct FStreamlineVersion
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	int32 Major;

	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	int32 Minor;

	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	int32 Build;

};

USTRUCT(BlueprintType)
struct FStreamlineFeatureRequirements
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	UStreamlineFeatureSupport Support;

	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	UStreamlineFeatureRequirementsFlags Requirements;

	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	FStreamlineVersion RequiredOperatingSystemVersion;

	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	FStreamlineVersion DetectedOperatingSystemVersion;

	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	FStreamlineVersion RequiredDriverVersion;

	UPROPERTY(BlueprintReadWrite, Category="Streamline")
	FStreamlineVersion DetectedDriverVersion;

};

UCLASS(MinimalAPI)
class UStreamlineLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*DisplayName = "Get Streamline Feature Requirements", */
	UFUNCTION(BlueprintPure, Category="Streamline", meta=(Keywords="Reflex, DLSS-G"))
	static void BreakStreamlineFeatureRequirements(UStreamlineFeatureRequirementsFlags Requirements, bool& D3D11Supported, bool& D3D12Supported, bool& VulkanSupported, bool& VSyncOffRequired, bool& HardwareSchedulingRequired);

	/** Checks whether a Streamline feature is supported by the current GPU. Further details can be retrieved via QueryStreamlineFeatureSupport*/
	UFUNCTION(BlueprintPure, Category="Streamline", meta=(DisplayName="Get NVIDIA Streamline Feature information", Keywords="Reflex, DLSS-G"))
	static FStreamlineFeatureRequirements GetStreamlineFeatureInformation(UStreamlineFeature Feature);

	/** Checks whether a Streamline feature is supported by the current GPU. Further details can be retrieved via QueryStreamlineFeatureSupport*/
	UFUNCTION(BlueprintPure, Category="Streamline", meta=(DisplayName="Is NVIDIA Streamline Feature Supported", Keywords="Reflex, DLSS-G"))
	static bool IsStreamlineFeatureSupported(UStreamlineFeature Feature);

	/** Checks whether Streamline feature  is supported by the current GPU	*/
	UFUNCTION(BlueprintPure, Category="Streamline", meta=(DisplayName="Query NVIDIA Streamline Feature Support", Keywords="Reflex, DLSS-G"))
	static UStreamlineFeatureSupport QueryStreamlineFeatureSupport(UStreamlineFeature Feature);

};

