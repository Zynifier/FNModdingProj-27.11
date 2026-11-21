// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortInitializationInterface.h"
#include "FortBallSpawner.generated.h"

class ABuildingGameplayActor;
class USphereComponent;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortBallSpawner : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortBallSpawner")
	TSubclassOf<ABuildingGameplayActor> BallToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortBallSpawner", meta=(EditInline="true"))
	TObjectPtr<USphereComponent> SphereComp;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortBallSpawner", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PreviewMeshComponent;
#endif

};

