// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Context/AthenaNewsStructs.h"
#include "FortAthenaMOTDTeaserWidget.generated.h"

class UFortAthenaMOTDSimpleNewsWidget;
class UFortAthenaMOTDTileListView;
class UFortAthenaMOTDWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAthenaMOTDTeaserWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	FAthenaMOTDBase GetNewsByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure)
	int32 GetNewsCount() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewsPopulated();

	UFUNCTION(BlueprintCallable)
	void OpenMOTDScreen(int32 FocusedNewsIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetViewConfiguration();

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDTeaserWidget")
	TSubclassOf<UFortAthenaMOTDWidget> MOTDWidgetClass;

	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDTeaserWidget")
	TSubclassOf<UFortAthenaMOTDSimpleNewsWidget> MOTDSimpleNewsWidgetClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDTeaserWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortAthenaMOTDTileListView> FortAthenaMOTDTileListView;

};

