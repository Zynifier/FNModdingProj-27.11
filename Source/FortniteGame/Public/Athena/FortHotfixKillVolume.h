// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "FortHotfixKillVolume.generated.h"

class AActor;
class UBoxComponent;
class UPrimitiveComponent;

UCLASS()
class AFortHotfixKillVolume : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(meta=(CallInEditor="true"))
	void CopyToClipboard();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditInstanceOnly, Export, Category="FortHotfixKillVolume", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> KillBoxComponent;

};

