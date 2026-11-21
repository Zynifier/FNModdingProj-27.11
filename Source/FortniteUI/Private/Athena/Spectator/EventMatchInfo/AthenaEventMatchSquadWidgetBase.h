// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "FortHUDElementWidget.h"
#include "AthenaEventMatchSquadWidgetBase.generated.h"

class UAthenaRemotePlayerViewData;
class UAthenaRemoteSquadViewData;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaEventMatchSquadWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Squad Widget")
	void SetSquadIdVisible(bool bSquadIdVisible);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleDisplaySessionRankChanged(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Squad Widget")
	void OnPlayerAdded(UAthenaRemoteSquadViewData* InSquadData, UAthenaRemotePlayerViewData* InPlayerData);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Squad Widget")
	void OnSquadColorChanged(UAthenaRemoteSquadViewData* InSquadData, FLinearColor InSquadColor);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Squad Widget")
	void OnSquadIdChanged(UAthenaRemoteSquadViewData* InSquadData, uint8 InSquadId);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Squad Widget")
	void OnSquadKillscoreChanged(UAthenaRemoteSquadViewData* InSquadData, int32 InSquadKills);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Squad Widget")
	void OnSquadPlaceChanged(UAthenaRemoteSquadViewData* InSquadData, int32 InSquadPlace);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Squad Widget")
	void OnSquadSessionRankChanged(UAthenaRemoteSquadViewData* InSquadData, int32 InSquadSessionRank);

	UPROPERTY(BlueprintReadOnly, Category="Event Match Squad Widget")
	TWeakObjectPtr<UAthenaRemoteSquadViewData> SquadData;

};

