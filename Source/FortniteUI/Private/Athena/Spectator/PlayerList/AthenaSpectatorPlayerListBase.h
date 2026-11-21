// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "AthenaSpectatorPlayerListBase.generated.h"

class UAthenaRemotePlayerViewData;
class UCommonListView;
enum class ESpectatorPlayerListSortMethod : uint8;

UENUM(BlueprintType)
enum class ESpectatorPlayerListSortMethod : uint8
{
	SquadId = 0,
	PlayerName = 1,
	Eliminations = 2,
	EventScore = 3,
	State = 4,
	Count = 5 UMETA(Hidden),
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorPlayerListBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void SetSortMethod(ESpectatorPlayerListSortMethod InNewSortMethod);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Current Sort Method Changed"))
	void BP_HandleCurrentSortMethodChanged(ESpectatorPlayerListSortMethod NewSortMethod);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Player Event Score Changed"))
	void BP_HandlePlayerEventScoreChanged(int32 EventScore);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView;

	UPROPERTY()
	TArray<TObjectPtr<UAthenaRemotePlayerViewData>> PlayerDataArray;

private:
	UPROPERTY(EditAnywhere, Category="AthenaSpectatorPlayerListBase", meta=(ArraySizeEnum="/Script/FortniteUI.ESpectatorPlayerListSortMethod", RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SortListRowHandles[5];

	UPROPERTY(EditAnywhere, Category="AthenaSpectatorPlayerListBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ShowPlayerProfileRowHandle;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Event Scores Visible"))
	bool bDesignTime_ShowEventScores;
#endif

};

