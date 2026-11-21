// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_Affiliation.generated.h"

UCLASS()
class UFortCheatManager_Affiliation : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void Affiliation_ResetAllRelations();

	UFUNCTION(Exec)
	void Affiliation_ResetFactionRelations();

	UFUNCTION(Exec)
	void Affiliation_ResetMemberRelations();

};

