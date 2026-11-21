// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaLoadoutWidget.generated.h"

class UAthenaLoadoutEntryWidget;
class UFortAthenaInventoryLoadout;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaLoadoutEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnLoadoutPicked();

	UFUNCTION(BlueprintNativeEvent)
	void SetLoadout(const UFortAthenaInventoryLoadout* NewLoadout);

protected:
	UPROPERTY()
	TObjectPtr<UFortAthenaInventoryLoadout> SelectedLoadout;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaLoadoutWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnLoadoutChosen(const UFortAthenaInventoryLoadout* SelectedLoadout);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void AddEntryWidget(UAthenaLoadoutEntryWidget* NewWidget);

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaLoadoutEntryWidget>> EntryWidgets;

	UPROPERTY(EditAnywhere, Category="AthenaLoadoutWidget")
	TSubclassOf<UAthenaLoadoutEntryWidget> EntryWidgetClass;

};

