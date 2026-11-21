// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortConversationGameEventMessages.generated.h"

class APlayerController;
class UFortNonPlayerConversationParticipantComponent;
class UUserWidget;

USTRUCT()
struct FConversationSettingDialogMarkerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftClassPtr<UUserWidget> DialogMarkerSoftClass;

};

USTRUCT(BlueprintType)
struct FFortConversationEnterEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortConversationEnterEvent")
	TObjectPtr<APlayerController> PlayerController;

};

USTRUCT(BlueprintType)
struct FFortConversationLeaveEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortConversationLeaveEvent")
	TObjectPtr<APlayerController> PlayerController;

};

USTRUCT()
struct FNPCConversationIndicatorMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortNonPlayerConversationParticipantComponent> NPCConversationComponent;

};

USTRUCT()
struct FFortConversation_NPC_AddIndicator : public FNPCConversationIndicatorMessage
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortConversation_NPC_RemoveIndicator : public FNPCConversationIndicatorMessage
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortConversation_SetDialogMarkerClassEvent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortConversation_Spectator_EnterConversation
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortConversation_Spectator_LeaveConversation
{
	GENERATED_BODY()

};

