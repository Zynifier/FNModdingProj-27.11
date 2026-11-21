// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Spectator/EventMatchInfo/AthenaEventScreenBase.h"
#include "AthenaEventMatchEliminatedGridScreenBase.generated.h"

class UAthenaEventMatchTeamWidgetBase;
class UAthenaRemotePlayerViewData;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaEventMatchEliminatedGridScreenBase : public UAthenaEventScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta=(DisplayName="OnTeamEliminated"))
	void OnTeamEliminated_BP();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaEventMatchEliminatedGridScreenBase")
	TSubclassOf<UAthenaEventMatchTeamWidgetBase> TeamWidgetClass;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaEventMatchEliminatedGridScreenBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaEventMatchTeamWidgetBase>> EliminatedTeams;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchEliminatedGridScreenBase")
	int32 MaxNumColumns;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchEliminatedGridScreenBase")
	int32 MaxTeamCount;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchEliminatedGridScreenBase")
	int32 MaxTeamSize;

private:
	UFUNCTION()
	void OnPlayerEliminatedStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsEliminated);

};

