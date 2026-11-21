// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ValetRaisinComponent.generated.h"

class AFortPlayerController;
class UAudioComponent;
class UFortItemDefinition;
class USoundAttenuation;
class USoundEffectSourcePresetChain;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UValetRaisinComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void ClientPickOption();

	UFUNCTION(BlueprintPure)
	UFortItemDefinition* GetSource() const;

protected:
	UPROPERTY(EditAnywhere, Category="ValetRaisinComponent")
	TObjectPtr<USoundAttenuation> AttenuationSettings;

	UPROPERTY(EditAnywhere, Category="ValetRaisinComponent")
	TObjectPtr<USoundEffectSourcePresetChain> PresetChain;

	UPROPERTY(EditAnywhere, Category="ValetRaisinComponent")
	bool bShouldManageOwnAudio;

private:
	UFUNCTION()
	void OnRep_Source();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSelectOption(AFortPlayerController* PlayerChoosing, const UFortItemDefinition* MusicSource);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> DynamicAudioComponent;

	UPROPERTY(ReplicatedUsing=OnRep_Source)
	TObjectPtr<UFortItemDefinition> ReplicatedSource;

};

