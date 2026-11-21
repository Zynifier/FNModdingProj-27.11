// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "AthenaEventMatchTeamWidgetBase.generated.h"

class UAthenaEventMatchPlayerWidgetBase;
class UAthenaRemotePlayerViewData;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaEventMatchTeamWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetTeamKills() const;

	UFUNCTION(BlueprintPure)
	bool IsTeamDead() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerWidgetAdded();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEventMatchTeamWidgetBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaEventMatchPlayerWidgetBase>> PlayerWidgets;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchTeamWidgetBase")
	uint8 SquadId;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchTeamWidgetBase")
	FLinearColor TeamColor;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchTeamWidgetBase")
	int32 MaxTeamSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaEventMatchTeamWidgetBase")
	TSubclassOf<UAthenaEventMatchPlayerWidgetBase> PlayerWidgetClass;

private:
	UFUNCTION()
	void OnPlayerDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsDead);

	UFUNCTION()
	void OnPlayerDisconnectedChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsDisconnected);

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UAthenaRemotePlayerViewData>> PlayerDatas;

};

