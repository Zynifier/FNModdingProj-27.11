// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "AthenaMarkerConfirmationWidget.generated.h"

class UImage;
class UMaterialInterface;
class UPanelWidget;

UCLASS(Abstract)
class FORTNITEUI_API UAthenaMarkerConfirmationWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaMarkerConfirmationWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void ShowMarkerConfirmations(const FFortWorldMarkerData& InMarkerData);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMarkerConfirmationWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> ConfirmationIconParent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMarkerConfirmationWidget")
	TObjectPtr<UMaterialInterface> ConfirmationIconAsset;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UImage>> ConfirmationIconPool;

};

