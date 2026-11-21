// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortTeamMemberEntryBase.generated.h"

enum class EGameReadiness : uint8;

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class UFortTeamMemberEntryBase : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsCurrentMemberLocal() const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentMemberValid() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnTeamMemberEstablished(bool bHasValidMember);

	UFUNCTION(BlueprintPure)
	EGameReadiness GetCurrentMemberGameReadiness() const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentMemberInFrontend() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnMemberGameReadinessChanged(EGameReadiness ReadyStatus);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMemberIsInFrontendChanged(bool bIsInFrontend);

};

