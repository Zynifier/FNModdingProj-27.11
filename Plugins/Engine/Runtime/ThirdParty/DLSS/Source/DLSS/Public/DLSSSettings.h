// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DLSSSettings.generated.h"

UENUM()
enum class EDLSSSettingOverride : uint8
{
	Enabled = 0 UMETA(DisplayName="True"),
	Disabled = 1 UMETA(DisplayName="False"),
	UseProjectSettings = 2 UMETA(DisplayName="Use project settings"),
};

UCLASS(Config=Engine, ProjectUserConfig)
class DLSS_API UDLSSOverrideSettings : public UObject
{
	GENERATED_BODY()

public:
	/** This enables DLSS/DLAA in editor viewports. Saved to local user config only.*/
	UPROPERTY(EditAnywhere, Config, Category="Level Editor - Viewport (Local)", meta=(DisplayName="Enable DLSS/DLAA to be turned on in Editor viewports"))
	EDLSSSettingOverride EnableDLSSInEditorViewportsOverride;

	/** This enables DLSS/DLAA in play in editor viewports. Saved to local user config only. */
	UPROPERTY(EditAnywhere, Config, Category="Level Editor - Viewport (Local)", meta=(DisplayName="Enable DLSS/DLAA in Play In Editor viewports"))
	EDLSSSettingOverride EnableDLSSInPlayInEditorViewportsOverride;

	/** This enables warnings about plugins & tools that are incompatible with DLSS/DLAA in the editor. Saved to local user config only. */
	UPROPERTY(EditAnywhere, Config, Category="Editor (Local)", meta=(DisplayName="Warn about incompatible plugins and tools"))
	bool bShowDLSSIncompatiblePluginsToolsWarnings;

	/** This enables on screen warnings and errors about DLSS/DLAA  */
	UPROPERTY(EditAnywhere, Config, Category="Editor (Local)", meta=(DisplayName="Show various DLSS/DLAA on screen debug messages"))
	EDLSSSettingOverride ShowDLSSSDebugOnScreenMessages;

};

UCLASS(Config=Engine, DefaultConfig, meta=(DisplayName="NVIDIA DLSS"))
class DLSS_API UDLSSSettings : public UObject
{
	GENERATED_BODY()

public:
	/** Enable DLSS/DLAA for D3D12, if the driver supports it at runtime */
	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(DisplayName="Enable DLSS/DLAA for the D3D12RHI"))
	bool bEnableDLSSD3D12;

	/** Enable DLSS/DLAA for D3D11, if the driver supports it at runtime */
	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(DisplayName="Enable DLSS/DLAA for the D3D11RHI"))
	bool bEnableDLSSD3D11;

	/** Enable DLSS/DLAA for Vulkan, if the driver supports it at runtime */
	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(DisplayName="Enable DLSS/DLAA for the VulkanRHI"))
	bool bEnableDLSSVulkan;

	/** This enables DLSS/DLAA in editor viewports. This project wide setting can be locally overridden in the NVIDIA DLSS (Local) settings.*/
	UPROPERTY(EditAnywhere, Config, Category="Level Editor - Viewport", meta=(DisplayName="Enable DLSS/DLAA to be turned on in Editor viewports"))
	bool bEnableDLSSInEditorViewports;

	/** This enables DLSS/DLAA in play in editor viewports. This project wide setting can be locally overridden in in the NVIDIA DLSS (Local) settings.*/
	UPROPERTY(EditAnywhere, Config, Category="Level Editor - Viewport", meta=(DisplayName="Enable DLSS/DLAA in Play In Editor viewports"))
	bool bEnableDLSSInPlayInEditorViewports;

	/** This enables on screen warnings and errors about DLSS/DLAA. This project wide setting can be locally overridden in the NVIDIA DLSS (Local) settings. */
	UPROPERTY(EditAnywhere, Config, Category="Level Editor - Viewport", meta=(DisplayName="Show various DLSS/DLAA on screen debug messages"))
	bool bShowDLSSSDebugOnScreenMessages;

	/** This is part of the DLSS plugin and used by most projects*/
	UPROPERTY(VisibleAnywhere, Config, Category="General Settings", meta=(DisplayName="Generic DLSS Binary Path"))
	FString GenericDLSSBinaryPath;

	UPROPERTY(VisibleAnywhere, Config, Category="General Settings", meta=(DisplayName="Exists"))
	bool bGenericDLSSBinaryExists;

	/** By default the DLSS plugin uses the UE Project ID to initialize DLSS. In some cases NVIDIA might provide a separate NVIDIA Application ID, which should be put here. Please refer to https://developer.nvidia.com/dlss for details*/
	UPROPERTY(EditAnywhere, Config, AdvancedDisplay, Category="General Settings", meta=(DisplayName="NVIDIA NGX Application ID"))
	uint32 NVIDIANGXApplicationId;

	/** In some cases NVIDIA might provide a project specific DLSS binary for your project. Please refer to https://developer.nvidia.com/dlss for details*/
	UPROPERTY(VisibleAnywhere, Config, AdvancedDisplay, Category="General Settings", meta=(DisplayName="Custom DLSS Binary Path"))
	FString CustomDLSSBinaryPath;

	UPROPERTY(VisibleAnywhere, Config, AdvancedDisplay, Category="General Settings", meta=(DisplayName="Exists"))
	bool bCustomDLSSBinaryExists;

};

