// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "FortAthenaLivingWorldEventData.h"
#include "FortAthenaLivingWorldPrefabActorSpawner.generated.h"

class AActor;
class AFortAthenaPatrolPath;
class UArrowComponent;
class UBillboardComponent;
class UFortSnapOnSurfaceComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortAthenaLivingWorldPrefabActorSpawner : public AActor
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorSpawned, AActor*, SpawnedActor);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnActorSpawnedDelegate, AActor*, SpawnedActor);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(AutoCreateRefTerm="DelegateToCall"))
	void CallWhenActorSpawned(const FOnActorSpawnedDelegate& DelegateToCall);

	UFUNCTION(BlueprintPure)
	AActor* GetSpawnedActor() const;

protected:
	UFUNCTION()
	void OnSnapCompleted(UFortSnapOnSurfaceComponent* Component, const FTransform& OldTransform, const FTransform& NewTransfom);

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FFortAthenaLivingWorldActorSpawnDescription ActorDescription;

	UPROPERTY(Transient)
	FOnActorSpawned OnActorSpawnedDelegate;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldPrefabActorSpawner")
	TObjectPtr<AFortAthenaPatrolPath> PatrolPath;

	UPROPERTY(VisibleAnywhere, TextExportTransient, Category="FortAthenaLivingWorldPrefabActorSpawner")
	FGuid Guid;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> SpawnedActor;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> ArrowComponent;
#endif

};

