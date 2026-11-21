// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortAthenaLocalGameplayBehavior.generated.h"

class AActor;
class UBillboardComponent;
class UFortAthenaBTTask_DynamicBlueprint;

UCLASS()
class AFortAthenaLocalGameplayBehavior : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="LocalGameplayBehavior")
	void FinishExecute();

	UFUNCTION(BlueprintImplementableEvent, Category="LocalGameplayBehavior")
	void OnAbort();

	UFUNCTION(BlueprintImplementableEvent, Category="LocalGameplayBehavior")
	void OnExecute(AActor* Activator);

private:
	UPROPERTY(EditAnywhere, Category="LocalGameplayBehavior")
	bool bNeedToAwakeDuringExecution;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaBTTask_DynamicBlueprint> CachedTask;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

};

