// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortPoi_DiscoverableComponent.generated.h"

class UFortQuestItemDefinition;
class USoundCue;

USTRUCT()
struct FEventDrivenDiscoveryID
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Discoverable")
	FString CalendarEventName;

	UPROPERTY(EditAnywhere, Category="Discoverable")
	bool bRequireEventActive;

	UPROPERTY(EditAnywhere, Category="Discoverable", meta=(ClampMax="255", ClampMin="-1"))
	int32 ActiveBitId;

};

UCLASS(MinimalAPI, meta=(BlueprintSpawnableComponent))
class UFortPoi_DiscoverableComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Discoverable", meta=(MakeEditWidget="TRUE"))
	FVector MapLocationTextLocationOffset;

protected:
	UPROPERTY(EditAnywhere, Category="Discoverable")
	FText PlayerFacingName;

	UPROPERTY(EditAnywhere, Category="Discoverable")
	TSoftObjectPtr<USoundCue> DiscoveredSoundCue;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Discoverable")
	bool bIsPlayerFacingNameLocalizable;
#endif

	UPROPERTY(EditAnywhere, Category="Discoverable")
	bool bDisableMapLocationText;

	UPROPERTY(EditAnywhere, Category="Discoverable")
	TSoftObjectPtr<UFortQuestItemDefinition> QuestPartOf;

	UPROPERTY(VisibleAnywhere, Category="Discoverable")
	FName QuestObjectiveBackendName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Discoverable", meta=(ClampMax="255", ClampMin="-1", DisplayName="Fixed Discovery Bit ID"))
	int32 DiscoverMinimapBitId;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Discoverable", meta=(TitleProperty="CalendarEventName"))
	TArray<FEventDrivenDiscoveryID> EventDrivenBitIds;

};

