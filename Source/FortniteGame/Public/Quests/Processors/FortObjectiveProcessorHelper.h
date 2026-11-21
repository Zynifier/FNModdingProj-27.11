// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "FortTeamEnum.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/Helpers/FortQueryHelpers.h"
#include "FortObjectiveProcessorHelper.generated.h"

class AActor;
class UObject;

UENUM()
enum class EDistanceTravelDirection : int32
{
	Any = 0,
	Vertical = 1,
	Horizontal = 2,
};

UENUM()
enum class EDistanceTravelMode : int32
{
	Any = 0,
	Ballooning = 1,
	Crouch = 2,
	DBNOCarried = 3,
	Driving = 4,
	Falling = 5,
	Floating = 6,
	Flying = 7,
	Goop = 8,
	Grinding = 9,
	Hover = 10,
	Parachuting = 11,
	Passenger = 12,
	RemoteControl_Flying = 13,
	Running = 14,
	Skating = 15,
	SkydiveFollowing = 16,
	SkyDiving = 17,
	Sliding = 18,
	SurfaceSwimming = 19,
	Swimming = 20,
	Ziplining = 21,
	ZipliningOnSpline = 22,
};

UENUM()
enum class EGameplayDebugState : uint8
{
	Unset = 0,
	Show = 1,
	Hide = 2,
};

UENUM()
enum class EVehicleSurfaceType : uint8
{
	None = 0,
	InAir = 1,
	InWater = 2,
	OnDirt = 3,
	OnGrass = 4,
	OnGround = 5,
	OnIce = 6,
	OnRoad = 7,
	OnSnow = 8,
};

USTRUCT()
struct FEventPayloadFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(EditCondition="bUseAdvancedInstigatorClassFilter"))
	FAdvancedClassFilter AdvancedInstigatorClassFilter;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(EditCondition="bUseInstigatorTags"))
	FGameplayTagQuery InstigatorTags;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(EditCondition="bUseAdvancedTargetClassFilter"))
	FAdvancedClassFilter AdvancedTargetClassFilter;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(EditCondition="bUseTargetTags"))
	FGameplayTagQuery TargetTags;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(EditCondition="bUseAdvancedObject1ClassFilter"))
	FAdvancedClassFilter AdvancedObject1ClassFilter;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(EditCondition="bUseAdvancedObject2ClassFilter"))
	FAdvancedClassFilter AdvancedObject2ClassFilter;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(ClampMin="0", EditCondition="bUseEventMagnitude", UIMin="0"))
	FFloatRange EventMagnitude;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(InlineEditConditionToggle))
	uint8 bUseAdvancedInstigatorClassFilter : 1;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(InlineEditConditionToggle))
	uint8 bUseInstigatorTags : 1;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(InlineEditConditionToggle))
	uint8 bUseAdvancedTargetClassFilter : 1;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(InlineEditConditionToggle))
	uint8 bUseTargetTags : 1;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(InlineEditConditionToggle))
	uint8 bUseAdvancedObject1ClassFilter : 1;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(InlineEditConditionToggle))
	uint8 bUseAdvancedObject2ClassFilter : 1;

	UPROPERTY(EditAnywhere, Category="EventPayloadFilter", meta=(InlineEditConditionToggle))
	uint8 bUseEventMagnitude : 1;

};

USTRUCT()
struct FFortObjectiveFilterType_NearbyPlayers
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_NearbyPlayers", meta=(InlineEditConditionToggle))
	bool bFilterEnabled;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_NearbyPlayers", meta=(EditCondition="bFilterEnabled"))
	TSet<TEnumAsByte<EFortTeamAffiliation::Type>> SpecificAffiliationsAllowed;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_NearbyPlayers", meta=(EditCondition="bFilterEnabled"))
	FGameplayTagQuery NearbyPlayersTagQuery;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_NearbyPlayers", meta=(ClampMax="4000", ClampMin="0", EditCondition="bFilterEnabled", ForceUnits="Meters"))
	FDoubleRange DistanceRange;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_NearbyPlayers", meta=(EditCondition="bFilterEnabled", UIMax="100", UIMin="0"))
	FInt32Range ExpectedPlayerCount;

};

USTRUCT()
struct FFortObjectiveFilterType_VehicleFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter")
	FObjectiveSubjectTags VehicleTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(EditCondition="bUseVehicleSurfaceType"))
	EVehicleSurfaceType RequiredSurfaceType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter")
	uint8 bAllowPassengerProgress : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(InlineEditConditionToggle))
	uint8 bUseVehicleSurfaceType : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter")
	uint8 bRequireVehicleBoost : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(InlineEditConditionToggle))
	uint8 bUseTravelSpeed : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(InlineEditConditionToggle))
	uint8 bUseVehicleHealthPercent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(InlineEditConditionToggle))
	uint8 bUseVehicleFuelPercent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(DisplayAfter="DistanceFromGround", EditCondition="RequiredSurfaceType == EVehicleSurfaceType::InAir"))
	uint8 bUseDistanceFromGround : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(EditCondition="bUseTravelSpeed", ForceUnits="km/h", UIMin="0"))
	FFloatRange TravelSpeed;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(EditCondition="bUseVehicleHealthPercent", UIMax="100", UIMin="0"))
	FFloatRange HealthPercent;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(EditCondition="bUseVehicleFuelPercent", UIMax="100", UIMin="0"))
	FFloatRange FuelPercent;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilterType_VehicleFilter", meta=(EditCondition="bUseDistanceFromGround && RequiredSurfaceType == EVehicleSurfaceType::InAir", ForceUnits="Meters", UIMax="1000", UIMin="0"))
	FFloatRange DistanceFromGround;

};

USTRUCT(BlueprintType)
struct FGameplayEventWeakData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	FGameplayTag EventTag;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	TWeakObjectPtr<AActor> Instigator;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	TWeakObjectPtr<AActor> Target;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	TWeakObjectPtr<UObject> OptionalObject;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	TWeakObjectPtr<UObject> OptionalObject2;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	FGameplayEffectContextHandle ContextHandle;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	FGameplayTagContainer InstigatorTags;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	FGameplayTagContainer TargetTags;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	float EventMagnitude;

	UPROPERTY(VisibleAnywhere, Category="GameplayEventWeakData")
	FGameplayAbilityTargetDataHandle TargetData;

};

