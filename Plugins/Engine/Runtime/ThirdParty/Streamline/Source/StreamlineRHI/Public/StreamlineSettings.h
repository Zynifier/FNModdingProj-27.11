// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StreamlineSettings.generated.h"

UENUM()
enum class EStreamlineSettingOverride : uint8
{
	Enabled = 0 UMETA(DisplayName="True"),
	Disabled = 1 UMETA(DisplayName="False"),
	UseProjectSettings = 2 UMETA(DisplayName="Use project settings"),
};

UCLASS(Config=Engine, ProjectUserConfig)
class STREAMLINERHI_API UStreamlineOverrideSettings : public UObject
{
	GENERATED_BODY()

public:
	/** Enable DLSS Frame Generation in play in editor viewports. Saved to local user config only. */
	UPROPERTY(EditAnywhere, Config, Category="Level Editor - Viewport (Local)", meta=(DisplayName="Enable DLSS-FG in Play In Editor viewports"))
	EStreamlineSettingOverride EnableDLSSFGInPlayInEditorViewportsOverride;

	/**
	 * Load the Streamline debug overlay in non-Shipping configurations. Note that the overlay requires DLSS Frame Generation to be available.
	 * Modifying this setting requires an editor restart to take effect. Saved to local user config only
	 */
	UPROPERTY(EditAnywhere, Config, Category="General Settings", meta=(DisplayName="Load Debug Overlay"))
	EStreamlineSettingOverride LoadDebugOverlayOverride;

};

UCLASS(Config=Engine, DefaultConfig, meta=(DisplayName="NVIDIA DLSS Frame Generation"))
class STREAMLINERHI_API UStreamlineSettings : public UObject
{
	GENERATED_BODY()

public:
	/** Enable plugin features for D3D12, if the driver supports it at runtime */
	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(DisplayName="Enable plugin features for the D3D12RHI"))
	bool bEnableStreamlineD3D12;

	/** Enable plugin features for D3D11, if the driver supports it at runtime */
	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(DisplayName="Enable plugin features for the D3D11RHI (Reflex only)"))
	bool bEnableStreamlineD3D11;

	/** Enable DLSS Frame Generation in play in editor viewports. This project wide setting can be locally overridden in the NVIDIA DLSS Frame Generation (Local) settings.*/
	UPROPERTY(EditAnywhere, Config, Category="Level Editor - Viewport", meta=(DisplayName="Enable DLSS-FG in Play In Editor viewports"))
	bool bEnableDLSSFGInPlayInEditorViewports;

	/**
	 * Load the Streamline debug overlay in non-Shipping configurations. Note that the overlay requires DLSS Frame Generation to be available.
	 * This project wide setting can be locally overridden in the NVIDIA DLSS Frame Generation (Local) settings.
	 * Modifying this setting requires an editor restart to take effect
	 */
	UPROPERTY(EditAnywhere, Config, Category="General Settings", meta=(DisplayName="Load Debug Overlay"))
	bool bLoadDebugOverlay;

	/** Allow OTA updates of Streamline features */
	UPROPERTY(EditAnywhere, Config, Category="General Settings", meta=(DisplayName="Allow OTA update"))
	bool bAllowOTAUpdate;

	/** By default the DLSS Frame Generation plugin uses the UE Project ID to initialize Streamline. In some cases NVIDIA might provide a separate NVIDIA Application ID, which should be put here. */
	UPROPERTY(EditAnywhere, Config, AdvancedDisplay, Category="General Settings", meta=(DisplayName="NVIDIA NGX Application ID"))
	int32 NVIDIANGXApplicationId;

};

