// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortAthenaTutorialManager.generated.h"

class AFortAthenaTutorialBase;
class APlayerStart;
class UUserWidget;

UCLASS()
class AFortAthenaTutorialManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, Category="Tutorial")
	void Server_OnTutorialScreenCompleted();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config")
	bool bPlayTutorials;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config")
	TArray<TObjectPtr<AFortAthenaTutorialBase>> TutorialsToExecute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config")
	TArray<TObjectPtr<AFortAthenaTutorialBase>> TutorialsToExecute_DefensiveBuildingFlow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config")
	TObjectPtr<AFortAthenaTutorialBase> InitialTutorial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config")
	FGameplayTag TutorialHUDTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config")
	FGameplayTag TopResourceTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config")
	FVector2D TopResourceNewPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaTutorialManager", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional))
	TObjectPtr<APlayerStart> Athena_Tutorial_Spawn_Point;

private:
	UFUNCTION(Server, Reliable, Category="Tutorial")
	void Server_OnClientReadyToStartMatch();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Manager Config", meta=(AllowPrivateAccess="TRUE"))
	bool ForceEnableDefensiveBuildingFlow;

	UPROPERTY(Replicated)
	int32 CurrentTutorialIndex;

	UPROPERTY(Transient)
	float GuidedTutorialTimeStart;

	UPROPERTY(Transient)
	float CurrentTutorialStepTimeStart;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialManager")
	FGameplayTagContainer InitialHUDTagsToDisable;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> TutorialHUD;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAthenaTutorialBase>> CurrentTutorialList;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialManager")
	FGameplayTag Tag_DisableClambering;

};

