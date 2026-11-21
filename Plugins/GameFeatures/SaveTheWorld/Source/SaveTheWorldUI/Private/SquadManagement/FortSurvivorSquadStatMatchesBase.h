// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "SquadManagement/FortSquadStatDetailsWidget.h"
#include "FortSurvivorSquadStatMatchesBase.generated.h"

class UFortSurvivorSquadStatMatchBase;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSurvivorSquadStatMatchesBase : public UFortSquadStatDetailsWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Management")
	FName GetIdOfSquadToManageBP() const;

	UFUNCTION(BlueprintCallable, Category="Squad Management")
	void SetIdOfSquadToManageBP(const FName& SquadId);

	UFUNCTION(BlueprintCallable, Category="Squad Management")
	void SetSummaryView(bool bInSummaryView);

	UFUNCTION(BlueprintPure, Category="Squad Management")
	bool TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management")
	TSubclassOf<UFortSurvivorSquadStatMatchBase> StatMatchClass;

	UPROPERTY(EditAnywhere, Category="Squad Management")
	bool bSummaryView;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management")
	void AddStatMatch(UFortSurvivorSquadStatMatchBase* SetBonus);

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management")
	void HandleDifferentSquadSetBP();

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortSurvivorSquadStatMatchBase>> StatMatches;

};

