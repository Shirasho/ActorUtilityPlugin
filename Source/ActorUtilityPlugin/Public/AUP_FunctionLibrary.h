#pragma once

#include "AUP_FunctionLibrary.generated.h"

UCLASS()
class ACTORUTILITYLIBRARY_API UActorUtilityFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Actor|Components", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static UActorComponent* AttachComponentOfClass(UObject* WorldContextObject, TSubclassOf<UActorComponent> ComponentClass, AActor* Owner, FName ComponentName = NAME_None, USceneComponent* AttachTo = nullptr, FName SocketName = NAME_None);
};