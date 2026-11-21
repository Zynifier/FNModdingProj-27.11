// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "Abilities/FortGameplayAbility.h"
#include "CreativeVideoPlayerFullscreenGameplayAbility.generated.h"

class UFortInputComponent;
class UGameplayEffect;
class UMediaSoundComponent;
class UMediaTexture;
class USoundSourceBus;
class UUserWidget;

UENUM(BlueprintType)
enum class ECreativeVideoPlayerFullscreenEffects : uint8
{
	/** Apply no Gameplay Effects */
	None = 0,
	/** Only apply No Collision */
	NoCollisionOnly = 1,
	/** Only apply No Damage */
	NoDamageOnly = 2,
	/** Apply both No Collision and No Damage */
	NoCollisionAndNoDamage = 3,
};

USTRUCT(BlueprintType)
struct FCreativeVideoPlayerFullscreenOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Fullscreen Options")
	ECreativeVideoPlayerFullscreenEffects GameplayEffects;

	UPROPERTY(EditAnywhere, Category="Fullscreen Options")
	bool bPromptFirst;

};

UCLASS(BlueprintType, Blueprintable)
class CREATIVEVIDEOPLAYERRUNTIME_API UCreativeVideoPlayerFullscreenGameplayAbility : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fullscreen Video Player")
	void EnterFullscreenState();

	UFUNCTION(BlueprintCallable, Category="Fullscreen Video Player")
	void EnterFullscreenStateWithOptions(FCreativeVideoPlayerFullscreenOptions Options);

	UFUNCTION(BlueprintCallable, Category="Fullscreen Video Player")
	void ExitFullscreenState();

	UFUNCTION(BlueprintCallable, Category="Fullscreen Video Player")
	void SetExternalComponents(UMediaTexture* ExtMediaTexture, USoundSourceBus* ExtSourceBus, UMediaSoundComponent* ExtMediaSoundComponent);

	UPROPERTY(EditDefaultsOnly, Category="Fullscreen Video Player")
	TSubclassOf<UGameplayEffect> NoCollisionGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="Fullscreen Video Player")
	TSubclassOf<UGameplayEffect> NoDamageGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="Fullscreen Video Player")
	TArray<TSubclassOf<UGameplayEffect>> AnimationStateGameplayEffectClasses;

	UPROPERTY(EditDefaultsOnly, Category="Fullscreen Video Player")
	TSubclassOf<UUserWidget> FullscreenWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Fullscreen Video Player")
	ECreativeVideoPlayerFullscreenEffects FullscreenEffects;

	UPROPERTY(EditDefaultsOnly, Category="Fullscreen Video Player")
	bool bPromptToConfirmFullscreen;

	UPROPERTY(EditDefaultsOnly, Category="Fullscreen Video Player")
	bool bIsDismissable;

private:
	UFUNCTION(Client, Reliable)
	void ClientLeaveFullscreenVideo();

	UFUNCTION(Client, Reliable)
	void ClientTransitionToFullscreenVideo();

	UFUNCTION()
	void HandleEnterFullscreenActionPressed();

	UFUNCTION()
	void HandleEnterFullscreenActionReleased();

	UFUNCTION()
	void OnFullscreenUIEnds();

	UFUNCTION(Server, Reliable)
	void ServerEnterFullscreenMode();

	UFUNCTION(Server, Reliable)
	void ServerLeaveFullscreenMode();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortInputComponent> OverrideMovementInputComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortInputComponent> SelectFullscreenModeInputComponent;

	UPROPERTY(Transient)
	TArray<FActiveGameplayEffectHandle> ActiveGameplayEffects;

	UPROPERTY(Transient)
	ECreativeVideoPlayerFullscreenEffects RequestedFullscreenEffects;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> VideoPlayerWidget;

	UPROPERTY(Transient)
	TObjectPtr<UMediaTexture> ExtMediaTextureCached;

	UPROPERTY(Transient)
	TObjectPtr<USoundSourceBus> ExtSourceBusCached;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> ExtMediaSoundComponentCached;

	UPROPERTY(Transient)
	bool bExtComponentsSet;

	UPROPERTY(Transient)
	bool bActivatedFullscreen;

};

