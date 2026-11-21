// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_VoiceChat.generated.h"

UENUM(BlueprintType)
enum class EFortAthenaMutator_VoiceChatChannelType : uint8
{
	Default = 0,
	None = 1,
	SquadOnly = 2,
	TeamOnly = 3,
	WholeServer = 4,
	ScopeOnly = 5,
	ScopeSquadOnly = 6,
	ScopeTeamOnly = 7,
};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_VoiceChat : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VoiceChat")
	FScalableFloat VoiceChatSetting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="VoiceChat")
	EFortAthenaMutator_VoiceChatChannelType ChannelType;

};

