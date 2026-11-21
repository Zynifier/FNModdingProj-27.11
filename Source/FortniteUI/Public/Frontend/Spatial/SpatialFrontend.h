// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortTypes.h"
#include "SpatialFrontend.generated.h"

class AFortEventLevelNavigationActor;
class UCommonLazyWidget;
class UFortGameStateComponent_EventLevel;
class UUserWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaSpatialFrontend : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventLevelTransitionBegin(const FGameplayTag& TargetCamera, const AFortEventLevelNavigationActor* TargetNavActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventLevelTransitionComplete(const FGameplayTag& ActiveCamera);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectedNavObjectChanged();

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UUserWidget> PersistentScreenWidget;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialFrontend")
	FGameplayTagContainer HidePersistentScreenCameraTags;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialFrontend")
	bool bHideCameraSpatialScreenOnTransistion;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialFrontend")
	EFortBangType BangType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyWidget> Lazy_ActiveScreen;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialFrontend", meta=(AllowPrivateAccess, Categories="ERG.Camera"))
	FGameplayTag StartingActiveCamera;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialFrontend", meta=(AllowPrivateAccess, Categories="ERG.Camera"))
	FGameplayTag ChallengesCameraTag;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialFrontend", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SelectObjectInputAction;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialFrontend")
	bool bEnableSpatialInputPreprocessingByDefault;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_EventLevel> EventGameStateComponent;

};

