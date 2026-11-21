// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddValkyrieComponents.generated.h"

class AActor;
class UActorComponent;

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EFortGameFeatureActionAddComponentMode : uint8
{
	None = 0 UMETA(Hidden),
	// If 0, this AddComponents action is essentially disabled

	Game = 1,
	// If Game bit is set, this action will run when the game instance runs

	Editor = 2,
};

USTRUCT()
struct FFortGameFeatureComponentEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Components", meta=(AllowAbstract="True"))
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category="Components")
	TSoftClassPtr<UActorComponent> ComponentClass;

	UPROPERTY(EditAnywhere, Category="Components")
	uint8 bClientComponent : 1;

	UPROPERTY(EditAnywhere, Category="Components")
	uint8 bServerComponent : 1;

	UPROPERTY(EditAnywhere, Category="Components", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EFortGameFeatureActionAddComponentMode"))
	uint8 WhenToInjectThisComponent;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Components (Valkyrie)"))
class UFortGameFeatureAction_AddValkyrieComponents : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Components", meta=(TitleProperty="{ActorClass} -> {ComponentClass}"))
	TArray<FFortGameFeatureComponentEntry> ComponentList;

};

