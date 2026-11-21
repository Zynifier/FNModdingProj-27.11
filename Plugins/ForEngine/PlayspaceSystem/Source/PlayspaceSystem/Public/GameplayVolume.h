// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Playspace.h"
#include "GameplayVolume.generated.h"

class AController;
class AGameplayVolume;
class APawn;
class APlayerState;
class APlayspace;
class UOverlapComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerOverlapVolume, APlayerState*, PlayerState, AGameplayVolume*, Volume);

UCLASS()
class PLAYSPACESYSTEM_API AGameplayVolume : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	APlayspace* GetPlayspace() const;

	UFUNCTION()
	virtual void UpdateSize(const FVector& NewScale);

protected:
	UFUNCTION()
	virtual void OnOverlappedPawnControllerChanged(APawn* Pawn, AController* OldController, AController* NewController);

	UPROPERTY(EditAnywhere, Category="GameplayVolume")
	TSoftClassPtr<APlayspace> PlayspaceClassTemplate;

	UPROPERTY(EditAnywhere, Category="GameplayVolume")
	EPlayspaceCreationType PlayspaceCreationType;

	UPROPERTY(Transient)
	TSubclassOf<APlayspace> PlayspaceClass;

	UPROPERTY(EditAnywhere, Category="GameplayVolume")
	bool bDestroyPlayspaceOnEndPlay;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<APlayspace> Playspace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="GameplayVolume")
	FGameplayTagContainer VolumeTags;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Volume", meta=(EditInline="true"))
	TObjectPtr<UOverlapComponent> BoundsComponent;

private:
	UFUNCTION(BlueprintCallable, Category="Volume")
	void InitializeBoundsComponent(UOverlapComponent* NewBoundsComponent);

};

