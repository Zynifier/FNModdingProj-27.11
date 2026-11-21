// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Spectator/EventMatchInfo/AthenaEventScreenBase.h"
#include "AthenaEventMatchActiveGridScreenBase.generated.h"

class UAthenaEventMatchTeamWidgetBase;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaEventMatchActiveGridScreenBase : public UAthenaEventScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta=(DisplayName="OnTeamChanged"))
	void OnTeamChanged_BP();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta=(DisplayName="OnTeamEliminated"))
	void OnTeamEliminated_BP();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaEventMatchActiveGridScreenBase")
	TSubclassOf<UAthenaEventMatchTeamWidgetBase> TeamWidgetClass;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaEventMatchActiveGridScreenBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaEventMatchTeamWidgetBase>> ActiveTeams;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchActiveGridScreenBase")
	int32 MaxNumColumns;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchActiveGridScreenBase")
	int32 MaxTeamCount;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEventMatchActiveGridScreenBase")
	int32 MaxTeamSize;

private:
	UFUNCTION()
	void OnTeamEliminated(int32 InSquadId);

};

