// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Validation/FortEditorValidator.h"
#include "FortValidator_FortExposedContent.generated.h"

class UFortExposedContentManifest;
class UFortExposedContentValidationWorldProxy;

UCLASS(Abstract)
class UFortValidator_FortExposedContent : public UFortEditorValidator
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortExposedContentManifest> CachedValidationManifest;

	UPROPERTY()
	int64 CachedValidationManifestFrameCount;

};

UCLASS()
class UFortValidator_FortExposedActorInstance : public UFortValidator_FortExposedContent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortExposedContentValidationWorldProxy> CachedValidationWorld;

};

UCLASS()
class UFortValidator_FortExposedActors : public UFortValidator_FortExposedContent
{
	GENERATED_BODY()

};

UCLASS()
class UFortValidator_FortExposedAssets : public UFortValidator_FortExposedContent
{
	GENERATED_BODY()

};

