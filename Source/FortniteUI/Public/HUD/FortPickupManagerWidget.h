// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Building/BuildingTypes.h"
#include "FortPickupManagerWidget.generated.h"

class UFortResourceWidget;
class UFortWorldItem;
class UPanelWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPickupManagerWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLowOnBuildingResources();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOutOfBuildingResources();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRefreshActiveResource(const EFortResourceType::Type CurrentResourceType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRefreshCounts();

	UFUNCTION(BlueprintImplementableEvent)
	void OnResourceItemPickedUp(const UFortWorldItem* Item, const int32 Count);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResourceWidgetVisibilityChanged(UFortResourceWidget* ResourceWidget);

private:
	UFUNCTION()
	void HandleHUDElementVisibilityRefreshed();

	UFUNCTION()
	void HandleSetWorldResourceWidgetVisibility(const EFortResourceType::Type ResourceType, const bool bVisible);

	UFUNCTION()
	void HandleWorldItemListChanged(const TArray<UFortWorldItem*>& ItemsAdded, const TArray<UFortWorldItem*>& ItemsRemoved);

	UFUNCTION()
	void HandleWorldItemsChanged();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_AllResources;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FortPickupManagerWidget", meta=(AllowPrivateAccess, EditInline="true"))
	TArray<TObjectPtr<UFortResourceWidget>> AdditionalResourceWidgetsToTrack;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortResourceWidget>> ResourceWidgets;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Active Resource Type"))
	TEnumAsByte<EFortResourceType::Type> DesignTime_ActiveResourceType;
#endif

};

