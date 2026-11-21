// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortStandaloneFrontend.generated.h"

class AFortPlayerPawn;
class APlayerController;
class UAthenaCustomizationScreenBase;
class UCommonActivatableWidget;
class UCommonButtonBase;
class UCommonWidgetSwitcherLegacy;
class UFortPocketLevel;
class UPocketLevelInstance;
class UWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActivatableScreenClosedEvent, UCommonActivatableWidget*, Widget, APlayerController*, Controller);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class FORTNITEUI_API UFortStandaloneFrontend : public UCommonActivatableWidget, public IFortPrimaryContentInterface, public IFortHUDShutdownTimerInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Phone Booth")
	bool bCosmeticRefreshOnClose;

	UPROPERTY(EditDefaultsOnly, Category="Phone Booth")
	float DelayCloseActionTimeSeconds;

protected:
	UFUNCTION(BlueprintCallable)
	void HandleCloseAction();

	UFUNCTION(BlueprintImplementableEvent, Category="Streaming")
	void OnBeginLoadingCameraLevel();

	UFUNCTION(BlueprintImplementableEvent, Category="Streaming")
	void OnCameraLevelLoaded();

	UFUNCTION(BlueprintImplementableEvent, Category="Streaming")
	void OnLoadingIndicatorShown(bool bShown);

	UFUNCTION(BlueprintCallable, Category="Streaming", meta=(BlueprintProtected="TRUE"))
	static void TriggerIncrementalGC();

	UPROPERTY(EditAnywhere, Category="Streaming")
	TObjectPtr<UFortPocketLevel> PocketLevel;

	UPROPERTY()
	TObjectPtr<UPocketLevelInstance> PocketLevelInstance;

	UPROPERTY(EditAnywhere, Category="Streaming")
	FVector CameraLevelLocation;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackActionRowHandle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStandaloneFrontend", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_TabContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Content_LoadingIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStandaloneFrontend", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaCustomizationScreenBase> ActivatableContent_Locker;

private:
	UFUNCTION()
	void HandleCloseRefreshComplete(AFortPlayerPawn* FortPawn);

	UPROPERTY(Transient)
	FFortAthenaLoadout InitialLoadoutData;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE", DisplayName="On Menu Closed"))
	FActivatableScreenClosedEvent OnMenuClosed;

	UPROPERTY(EditAnywhere, Category="Primary Content Settings")
	FPrimaryContentSetup PrimaryContentSetup;

};

