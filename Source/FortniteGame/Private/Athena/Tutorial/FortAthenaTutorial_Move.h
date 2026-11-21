// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Move.generated.h"

class AActor;
class AFortAthenaTutorialMarker;
class AFortStaticMeshActor;
class ATriggerBox;

UCLASS()
class AFortAthenaTutorial_Move : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> JumpMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> JumpArrows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<ATriggerBox> JumpTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<ATriggerBox> JumpEndTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> CrouchMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> CrouchArrows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<ATriggerBox> CrouchTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<ATriggerBox> CrouchEndTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<AFortStaticMeshActor> BlockerJump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move Tutorial Actors")
	TObjectPtr<AFortStaticMeshActor> BlockerCrouch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer JumpHUDElementTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer CrouchHUDElementTags;

private:
	UFUNCTION()
	void OnBeginOverlapCrouchEndTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnBeginOverlapCrouchTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnBeginOverlapJumpEndTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnBeginOverlapJumpTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

};

