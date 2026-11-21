// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_ScriptBase.h"
#include "FortAthenaAISpawnerDataComponent_Verse.generated.h"

class UAIBehaviorScript;
class UEntityComponent;

UCLASS()
class VERSEFORTNITE_API UFortAthenaAISpawnerDataComponent_Verse : public UFortAthenaAISpawnerDataComponent_ScriptBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddUniqueEntityComponent(TSubclassOf<UEntityComponent> EntityComponent);

	UFUNCTION(BlueprintCallable)
	void SetAIBehaviorScript(UAIBehaviorScript* InAIBehaviorScript);

private:
	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UEntityComponent>> EntityComponents;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TWeakObjectPtr<UAIBehaviorScript> AIBehaviorScript;

};

