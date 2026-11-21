// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_Interaction.generated.h"

class AActor;

UCLASS()
class UFortContextualTutorial_Interaction : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleInteractSuccessTrigger(const FGameplayTag Tags, int32 Count);

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> WeakInstigatingActor;

};

