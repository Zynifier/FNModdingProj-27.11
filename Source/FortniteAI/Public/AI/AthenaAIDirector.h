// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAIDirector.h"
#include "AthenaAIDirector.generated.h"

class AActor;
class AAthenaAIController;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Replication", "Object", "Actor", "Advanced", "Replication"))
class AAthenaAIDirector : public AFortAIDirector
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	static void AggroOnActor(const AAthenaAIController* AIController, AActor* Target);

};

