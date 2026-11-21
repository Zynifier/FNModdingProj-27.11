// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/GamePhaseWidget.h"
#include "AthenaGamePhaseWidgetBase.generated.h"

class UMaterialInterface;
class UTextBlock;
enum class EAthenaGamePhaseStep : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaGamePhaseWidgetBase : public UGamePhaseWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateGamePhaseIcon(EAthenaGamePhaseStep GamePhaseStep);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_RemainingTime;

private:
	UFUNCTION()
	void HandleCountdownUpdate(int32 TimeRemaining);

	UPROPERTY(EditAnywhere, Category="Storm Coming")
	TObjectPtr<UMaterialInterface> StormComingFontMaterial;

	UPROPERTY(EditAnywhere, Category="Storm Coming")
	float StormComingWarningTime;

};

