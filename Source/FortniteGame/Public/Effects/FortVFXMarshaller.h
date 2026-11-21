// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Particles/ParticleSystemComponent.h"
#include "Effects/FortVFXMarshallingTypes.h"
#include "FortVFXMarshaller.generated.h"

class AActor;
class UFXSystemComponent;
class UMaterialInterface;
class UObject;
class USceneComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMarshalledComponentsCreated_BP);

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortVFXMarshaller : public UActorComponent, public IFortVFXDataOwner
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void ActivateAll();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void Cleanup();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void DeactivateAll();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void Setup();

private:
	UPROPERTY(EditAnywhere, Category="Config")
	FMarshalledVFXAuthoredData AuthoredData;

	UPROPERTY(Transient)
	FMarshalledVFXRuntimeData RuntimeData;

};

UCLASS()
class UMarshalledVFX_HelperLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Systems", meta=(AutoCreateRefTerm="Tags", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Activate Managed Particles", Keywords="DoNotUse"))
	static void ActivateMatching(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& Tags, bool bReset = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Systems", meta=(BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Remove Managed Particles", Keywords="DoNotUse"))
	static void CleanupDependentVFX(UPARAM(DisplayName="Particle Owner") UObject* Context);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Systems", meta=(AutoCreateRefTerm="Tags", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Deactivate Managed Particles", Keywords="DoNotUse"))
	static void DeactivateMatching(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Systems", meta=(AutoCreateRefTerm="WithMatching", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Get Managed Particles", Keywords="DoNotUse"))
	static TArray<UFXSystemComponent*> GetMatchingSystemComponents(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Systems", meta=(AdvancedDisplay="Class", AutoCreateRefTerm="WithMatching", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DeterminesOutputType="Class", DisplayName="(defunct) Get Managed Particles As", Keywords="DoNotUse"))
	static TArray<UFXSystemComponent*> GetMatchingSystemComponentsAs(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, TSubclassOf<UFXSystemComponent> Class);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="Mappings", BlueprintInternalUseOnly="true", BlueprintType="true", DisplayName="(defunct) Fixup Particle Names", Keywords="DoNotUse"))
	static TArray<FParticleSysParam> MapParticleInstanceParamNames(const TMap<FName, FParameterNameMapping>& Mappings, UPARAM(ref) TArray<FParticleSysParam>& Params, UFXSystemComponent* ForComponent);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="WithMatching", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Actor Parameter (Managed Particles)", Keywords="DoNotUse"))
	static void SetActorParam(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, FName Name, AActor* Value);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Config", meta=(BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Managed Particle Root", Keywords="DoNotUse"))
	static void SetBaseForSystems(UPARAM(DisplayName="Particle Owner") UObject* Context, USceneComponent* Base);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="WithMatching", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Boolean Parameter (Managed Particles)", Keywords="DoNotUse"))
	static void SetBoolParam(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, FName Name, bool Value);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="WithMatching,Value", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Color Parameter (Managed Particles)", Keywords="DoNotUse"))
	static void SetColorParam(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, FName Name, const FLinearColor& Value);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="WithMatching", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Float Parameter (Managed Particles)", Keywords="DoNotUse"))
	static void SetFloatParam(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, FName Name, float Value);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="WithMatching", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Int Parameter (Managed Particles)", Keywords="DoNotUse"))
	static void SetIntParam(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, FName Name, int32 Value);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="WithMatching", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Material Parameter (Managed Particles)", Keywords="DoNotUse"))
	static void SetMaterialParam(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, FName Name, UMaterialInterface* Value);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Systems", meta=(BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Spawn Managed Particles", HidePin="bPointersAreSafeToRetain", Keywords="DoNotUse"))
	static void SetupDependentVFX(UPARAM(DisplayName="Particle Owner") UObject* Context, bool bPointersAreSafeToRetain = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ManagedParticles|Parameters", meta=(AutoCreateRefTerm="WithMatching,Value", BlueprintInternalUseOnly="true", BlueprintType="true", DefaultToSelf="Context", DisplayName="(defunct) Set Vector Parameter (Managed Particles)", Keywords="DoNotUse"))
	static void SetVectorParam(UPARAM(DisplayName="Particle Owner") UObject* Context, const FGameplayTagContainer& WithMatching, FName Name, const FVector& Value);

};

