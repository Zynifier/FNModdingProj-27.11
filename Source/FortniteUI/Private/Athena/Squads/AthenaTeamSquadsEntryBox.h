// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/DynamicEntryBoxBase.h"
#include "AthenaTeamSquadsEntryBox.generated.h"

class UAthenaTeamSquadEntry;

UCLASS()
class UAthenaTeamSquadsEntryBox : public UDynamicEntryBoxBase
{
	GENERATED_BODY()

public:
	UAthenaTeamSquadsEntryBox(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="AthenaTeamSquadsEntryBox")
	TSubclassOf<UAthenaTeamSquadEntry> SquadEntryClass;

	UPROPERTY(EditAnywhere, Category="AthenaTeamSquadsEntryBox")
	bool bDisplayEmptySquads;

};

