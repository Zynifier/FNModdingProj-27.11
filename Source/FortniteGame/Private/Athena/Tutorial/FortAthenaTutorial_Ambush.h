// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Ambush.generated.h"

class AActor;
class ABuildingSMActor;
class AController;
class AFortAIPawn;
class AFortAthenaAIBotController;
class AFortAthenaTutorialMarker;
class AFortPawn;
class AFortStaticMeshActor;
class ATriggerBox;
class UPrimitiveComponent;

UCLASS()
class AFortAthenaTutorial_Ambush : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnAmbushBotSpawned(AFortPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent)
	bool SpawnAmbushBot();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> ReachAmbushLocationMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TObjectPtr<ATriggerBox> AmbushTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TSubclassOf<AActor> HealItemSpawnerBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TSubclassOf<AActor> ShieldItemSpawnerBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TObjectPtr<AFortStaticMeshActor> BlockerAmbush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> AmbushDirectionArrows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TObjectPtr<AActor> AmbushCameraPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TObjectPtr<ABuildingSMActor> AISpawnerAttachedTo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ambush Tutorial Actors")
	TObjectPtr<AFortAIPawn> SpawnedAIPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer HealthHUDElementTags;

	UPROPERTY(EditAnywhere, Category="Ai Properties")
	float AiAccuracyRadius;

	UPROPERTY(EditAnywhere, Category="Ai Properties")
	float AiRateOfFire;

	UPROPERTY(EditAnywhere, Category="Ai Properties")
	float AiFirstShotDamage;

	UPROPERTY(EditAnywhere, Category="Ai Properties")
	float AiDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ambush Tutorial AI Bot")
	FName MaxLocationErrorKeyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ambush Tutorial AI Bot")
	float MaxLocationErrorValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ambush Tutorial AI Bot")
	FName MinLocationErrorKeyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ambush Tutorial AI Bot")
	float MinLocationErrorValue;

private:
	UFUNCTION()
	void HandleOnAIDummyDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleOnPlayerDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnBeginOverlapAmbushTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> BotController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float AmbushCameraInSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float AmbushCameraOutSpeed;

};

