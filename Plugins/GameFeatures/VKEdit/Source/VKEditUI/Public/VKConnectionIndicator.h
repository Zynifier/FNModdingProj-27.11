// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "DownloadOnDemand/DownloadOnDemandEventContexts.h"
#include "FortMemorySamplerTypes.h"
#include "Minigame/FortMinigameTypes.h"
#include "VKConnectionIndicator.generated.h"

class UAthenaSquadListBase;
class UCommonActionWidget;
class UCommonTextBlock;
class UFortSimpleMaterialProgressBar;
class UImage;
class UObject;
class UPanelWidget;
class UWidgetSwitcher;
enum class EFortMinigameState : uint8;

UCLASS(Config=Game, DefaultConfig, ClassGroup=("UI"), meta=(Category="VK Connection Indicator", DisableNativeTick))
class UVKConnectionIndicator : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnMinigameStateChanged(const EFortMinigameState MinigameState, const EFortMinigameState PreviousMinigameState);

	UPROPERTY(EditDefaultsOnly, Category="VKConnectionIndicator", meta=(ArraySizeEnum="/Script/FortniteGame.EVkEditStatus"))
	FText EditStatusLocalizedText[10];

	UPROPERTY(EditDefaultsOnly, Category="VKConnectionIndicator", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle OpenLogInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Not Connected"))
	TObjectPtr<UObject> StatusIcon_NotConnected;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Connected"))
	TObjectPtr<UObject> StatusIcon_Connected;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Refresh Required"))
	TObjectPtr<UObject> StatusIcon_RefreshRequired;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Preparing"))
	TObjectPtr<UObject> StatusIcon_Preparing;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Downloading"))
	TObjectPtr<UObject> StatusIcon_Downloading;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Up To Date"))
	TObjectPtr<UObject> StatusIcon_UpToDate;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Starting Game"))
	TObjectPtr<UObject> StatusIcon_StartingGame;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Game In Progress"))
	TObjectPtr<UObject> StatusIcon_GameInProgress;

	UPROPERTY(EditDefaultsOnly, Category="Status Icons", meta=(AllowedClasses="/Script/Engine.Texture, /Script/Engine.MaterialInterface, /Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Error"))
	TObjectPtr<UObject> StatusIcon_Error;

	UPROPERTY(BlueprintReadOnly, Export, Category="VKConnectionIndicator", meta=(BindWidget, BlueprintProtected, EditInline="true"))
	TObjectPtr<UImage> Image_StatusIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StatusMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_AdditionalInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_DownloadContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSimpleMaterialProgressBar> ProgressBar_Download;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DownloadProgress;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_OpenLogContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> Action_OpenLog;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_SubMessageContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SubMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EditMode;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_SquadListContainer;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaSquadListBase> AthenaSquadList;

private:
	UFUNCTION()
	void HandleMemorySamplerProgressUpdated(float Progress);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Apply Design Time Values"))
	bool bDesignTime_ApplyDesignTimeValues;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Has Active Connection", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	bool bDesignTime_HasActiveConnection;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Memory Sampler State", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	EMemorySamplerState DesignTime_MemorySamplerState;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="VK Edit Status", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	EVkEditStatus DesignTime_VkEditStatus;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Download Progress", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	float DesignTime_DownloadProgress;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Set Minigame State", EditCondition="bDesignTime_ApplyDesignTimeValues"))
	bool bDesignTime_SetMinigameState;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Minigame State", EditCondition="bDesignTime_SetMinigameState"))
	EFortMinigameState DesignTime_MinigameState;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Minigame State", EditCondition="bDesignTime_SetMinigameState"))
	EFortMinigameState DesignTime_PreviousMinigameState;
#endif

};

