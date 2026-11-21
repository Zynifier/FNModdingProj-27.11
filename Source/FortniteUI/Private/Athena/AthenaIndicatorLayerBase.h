// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "FortHUDElementWidget.h"
#include "AthenaIndicatorLayerBase.generated.h"

class UAthenaPlayerIndicatorBase;
class UAthenaPlayerViewModel;
class UFortActorCanvas;
class USlateVectorArtData;

UCLASS(Abstract)
class UAthenaIndicatorLayerBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleIndicatorModeChanged(bool bIndicatorsEnabled);

	UFUNCTION()
	void OnTargetChangedNative(bool bTargeting);

	UFUNCTION(BlueprintImplementableEvent, Category="Game")
	void OnTargetingChanged(bool bTargeting);

	UPROPERTY(BlueprintReadOnly, Export, Category="Indicator", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActorCanvas> GeneralIndicators;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActorCanvas> NameIndicators;

	UPROPERTY(EditDefaultsOnly, Category="AthenaIndicatorLayerBase")
	TSubclassOf<UAthenaPlayerIndicatorBase> PlayerIndicatorClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaIndicatorLayerBase")
	int32 PlayerIndicatorPoolSize;

	UPROPERTY(Transient)
	FUserWidgetPool PlayerIndicatorWidgetPool;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaPlayerViewModel> PlayerVM;

	UPROPERTY(EditAnywhere, Category="Indicator")
	TObjectPtr<USlateVectorArtData> TeamIndicatorMesh;

	UPROPERTY()
	bool bWasTargeting;

};

