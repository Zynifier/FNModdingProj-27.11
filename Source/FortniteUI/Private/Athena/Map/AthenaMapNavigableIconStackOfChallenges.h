// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Athena/Map/AthenaMapNavigableIcon.h"
#include "AthenaMapNavigableIconStackOfChallenges.generated.h"

class UCommonActionWidget;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaMapNavigableIconStackOfChallenges : public UAthenaMapNavigableIcon
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CycleStackedData();

	UFUNCTION(BlueprintPure)
	int32 GetSelectStackedDataIndex() const;

	UFUNCTION(BlueprintPure)
	int32 GetStackedDataCount() const;

	UFUNCTION(BlueprintCallable)
	void SelectStackedDataAt(int32 InSelectedStackedDataIndex);

	UFUNCTION(BlueprintPure)
	bool ShouldCycleAutomatically() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChangedStackData(int32 NewStackCount, int32 NonCompletedCount);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> CommonActionWidget_Cycle;

	UPROPERTY(EditAnywhere, Category="AthenaMapNavigableIconStackOfChallenges", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CycleStackInputAction;

};

