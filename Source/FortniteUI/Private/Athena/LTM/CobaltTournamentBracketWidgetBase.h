// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltTournamentBracketWidgetBase.generated.h"

class UCobaltTournamentBracketNodeWidgetBase;

UCLASS()
class UCobaltTournamentBracketWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateTournamentBracket(int32 CurrentActiveRound);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTournamentBracket_BP(int32 CurrentActiveRound);

	UPROPERTY(BlueprintReadWrite, Export, Category="CobaltTournamentBracketWidgetBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UCobaltTournamentBracketNodeWidgetBase>> LocalTeamNodes;

	UPROPERTY(BlueprintReadWrite, Export, Category="CobaltTournamentBracketWidgetBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UCobaltTournamentBracketNodeWidgetBase>> EnemyTeamNodes;

};

