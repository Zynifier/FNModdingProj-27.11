// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "FortHUDElementWidget.h"
#include "AthenaMarkerDetails.generated.h"

class UAthenaMarkerPointer;
class UFortMarkerDetailsTable;
class UFortWorldMarker;
enum class EFortMarkerActions : uint8;

UENUM(BlueprintType)
enum class EFortMarkerActions : uint8
{
	None = 0,
	Cancel = 1,
	Confirm = 2,
	CancelAndReturnNPC = 3,
	Unconfirm = 4,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaMarkerDetails : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMarkerAction(EFortMarkerActions MarkerAction);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMarkerConfirmations(const FFortWorldMarkerData& MarkerData);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMarkerData(const FFortWorldMarkerData& MarkerData);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMarkerDetails", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaMarkerPointer> MarkerPointer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMarkerDetails")
	TObjectPtr<UFortMarkerDetailsTable> DetailsTable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaMarkerDetails")
	TObjectPtr<UFortWorldMarker> FortWorldMarker;

};

