// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "CustomAccessoryAttachmentData.generated.h"

UCLASS(BlueprintType)
class UCustomAccessoryAttachmentData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Attachment", meta=(DisplayName="Medium Male Relative Scale"))
	FVector MaleRelativeScale;

	UPROPERTY(EditDefaultsOnly, Category="Attachment", meta=(DisplayName="Medium Female Relative Scale"))
	FVector FemaleRelativeScale;

	UPROPERTY(EditDefaultsOnly, Category="Attachment")
	FVector SmallMaleRelativeScale;

	UPROPERTY(EditDefaultsOnly, Category="Attachment")
	FVector SmallFemaleRelativeScale;

	UPROPERTY(EditDefaultsOnly, Category="Attachment")
	FVector LargeMaleRelativeScale;

	UPROPERTY(EditDefaultsOnly, Category="Attachment")
	FVector LargeFemaleRelativeScale;

};

