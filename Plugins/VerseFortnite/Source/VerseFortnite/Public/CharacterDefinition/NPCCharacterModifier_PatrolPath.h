// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/Creative/FortCreativePatrolPath.h"
#include "CharacterDefinition/NPCCharacterModifier.h"
#include "NPCCharacterModifier_PatrolPath.generated.h"

class AActor;
class AFortAthenaPatrolPath;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisplayName="NPC Character Patrol Path"))
class UNPCCharacterModifier_PatrolPath : public UNPCCharacterModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	AFortAthenaPatrolPath* GetPatrolPathToAssign(AActor* ModifierOwner);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Patrol Path", meta=(AllowPrivateAccess="true"))
	EFortCreativePatrolPathGroup PatrolPathGroup;

};

