// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Clambering.generated.h"

class AActor;
class AFortAthenaTutorialMarker;
class ATriggerBox;

UCLASS()
class AFortAthenaTutorial_Clambering : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamber Tutorial Actors", meta=(BindWidget))
	TObjectPtr<AFortAthenaTutorialMarker> ClamberMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamber Tutorial Actors", meta=(BindWidget))
	TObjectPtr<AFortAthenaTutorialMarker> ClamberArrows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamber Tutorial Actors", meta=(BindWidget))
	TObjectPtr<ATriggerBox> ClamberTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamber Tutorial Actors", meta=(BindWidget))
	TObjectPtr<ATriggerBox> ClamberEndTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags", meta=(BindWidget))
	FGameplayTagContainer ClamberHUDElementTags;

private:
	UFUNCTION()
	void OnBeginOverlapClamberEndTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnBeginOverlapClamberTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorial_Clambering")
	FGameplayTag Tag_DisableClambering;

};

