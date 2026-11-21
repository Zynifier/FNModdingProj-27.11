// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"
#include "FortCreativeEventSystemType.generated.h"

UENUM()
enum class EFortCreativeEventSystemType : uint8
{
	/** Link devices using channel IDs and broadcast via the legacy messaging router */
	Channels = 0 UMETA(DisplayName="Channels (Legacy Router)"),
	/** Link devices using channel IDs and broadcast via the event router */
	ChannelsWithEvents = 1 UMETA(DisplayName="Channels (Event Router)", Hidden),
	/** Link devices using direct binding and broadcast via the event router */
	DirectBinding = 2 UMETA(DisplayName="Direct Event Binding"),
};

UENUM(BlueprintType)
enum class EFortGameplayEventReferenceType : uint8
{
	None = 0,
	EventDescriptor = 1,
	EventFunction = 2,
};

USTRUCT()
struct FFortGameplayEventObjectHandle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	FSoftObjectPath ObjectRef;

	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	int32 ObjectTrackingGUID;

};

USTRUCT()
struct FFortGameplayEventReference
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	FFortGameplayEventObjectHandle ObjectHandle;

	UPROPERTY(EditInstanceOnly, Category="Gameplay Event")
	EFortGameplayEventReferenceType EventRefType;

	UPROPERTY(EditAnywhere, Category="Gameplay Event")
	FName EventRefMemberName;

};

USTRUCT()
struct FFortGameplayEventContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="Gameplay Event")
	TArray<FFortGameplayEventReference> EventRefs;

};

USTRUCT()
struct FORTNITEGAME_API FFortGameplayEventContainer_Named : public FFortGameplayEventContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="Gameplay Event")
	FName EventName;

};

