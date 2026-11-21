// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Sound/FortSoundLibraryComponents.h"
#include "Sound/FortSoundLibraryContexts.h"
#include "FortSoundLibrary_HitNotify.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EFortHitNotifyAudioPerspective : uint8
{
	Invalid = 0,
	Instigate = 1,
	Receive = 2,
	Observe = 3,
};

UENUM(BlueprintType)
enum class EFortHitNotifyAudioType : uint8
{
	Invalid = 0,
	Body = 1,
	BodyCrit = 2,
	Shield = 3,
	ShieldCrit = 4,
	Death = 5,
	DeathCrit = 6,
	Fall = 7,
	FallDeath = 8,
};

USTRUCT(BlueprintType)
struct FFortHitNotifyContextSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHitNotifyContextSettings")
	EFortHitNotifyAudioType HitType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHitNotifyContextSettings")
	EFortHitNotifyAudioPerspective HitPerspective;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHitNotifyContextSettings")
	FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHitNotifyContextSettings")
	FGameplayEffectContextHandle EffectContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHitNotifyContextSettings")
	TWeakObjectPtr<AActor> DamageCauser;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHitNotifyContextSettings")
	TWeakObjectPtr<AActor> DamageReceiver;

};

UCLASS(BlueprintType, HideCategories=("Tags", "ComponentReplication", "Sockets", "Activation", "Cooking", "Collision", "ComponentTick", "AssetUserData", "Replication", "Variable", "Navigation"))
class UFortHitNotifySoundLibraryComponent : public UFortSoundLibraryComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void ConfigureContext(const FFortHitNotifyContextSettings& InContextSettings);

};

UCLASS(BlueprintType)
class UFortHitNotifySoundLibraryContext : public UFortSoundLibraryContext
{
	GENERATED_BODY()

};

