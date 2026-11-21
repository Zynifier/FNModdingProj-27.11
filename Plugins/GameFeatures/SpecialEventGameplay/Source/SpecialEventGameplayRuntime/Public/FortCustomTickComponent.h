// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "CommonInputTypes.h"
#include "FortCustomTickComponent.generated.h"

class UFortCustomTickComponent;

UENUM(BlueprintType)
enum class EFortCustomTickComponentCondition : uint8
{
	/** If we were recently rendered, NumFramesToSkipBetweenCustomTicks is MinFramesToSkipBetweenCustomTicks.  Otherwise, MaxFramesToSkipBetweenCustomTicks. */
	WasRecentlyRendered = 0,
	/** NumFramesToSkipBetweenCustomTicks is scaled between Min/MaxFramesToSkipBetweenCustomTicks across Inner/OuterDistance
	  * to the nearest camera location of locally controlled players (or ALL players on authority) */
	CameraDistance = 1,
	/** NumFramesToSkipBetweenCustomTicks is scaled between Min/MaxFramesToSkipBetweenCustomTicks across Inner/OuterDistance
	  * to the nearest location of locally controlled players (or ALL players on authority) */
	LocalPlayerDistance = 2,
	Count = 3 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortCustomTickComponentTick, UFortCustomTickComponent*, CustomTickComonent, const float, DeltaTime);

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FCustomTickComonentQualitySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CustomTickComonentQualitySettings", meta=(ClampMin="0", UIMin="0"))
	int32 NumFramesToSkipBetweenEvaluations;

	UPROPERTY(EditDefaultsOnly, Category="CustomTickComonentQualitySettings", meta=(ClampMin="0", UIMin="0"))
	int32 MinFramesToSkipBetweenCustomTicks;

	UPROPERTY(EditDefaultsOnly, Category="CustomTickComonentQualitySettings", meta=(ClampMin="0", UIMin="0"))
	int32 MaxFramesToSkipBetweenCustomTicks;

	UPROPERTY(EditDefaultsOnly, Category="CustomTickComonentQualitySettings", meta=(ClampMin="0.0", UIMin="0.0"))
	float InnerDistance;

	UPROPERTY(EditDefaultsOnly, Category="CustomTickComonentQualitySettings", meta=(ClampMin="0.0", UIMin="0.0"))
	float OuterDistance;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AssetUserData", "Collision", "ComponentReplication", "Cooking", "Replication"), meta=(BlueprintSpawnableComponent))
class UFortCustomTickComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortCustomTickComponent")
	EFortCustomTickComponentCondition Condition;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomTickComponent")
	FGameplayTag AuthorityQualitySettingsTag;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomTickComponent")
	FGameplayTag DefaultClientQualitySettingsTag;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomTickComponent")
	TMap<ECommonPlatformType, FGameplayTag> ClientPlatformQualitySettingsTagMap;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomTickComponent")
	TMap<FGameplayTag, FCustomTickComonentQualitySettings> QualitySettingsMap;

	UPROPERTY(EditDefaultsOnly, Category="WasRecentlyRendered Condition")
	float WasRecentlyRenderedTolerance;

	UPROPERTY(BlueprintAssignable)
	FFortCustomTickComponentTick OnCustomTick;

};

